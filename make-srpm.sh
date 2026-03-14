#!/bin/bash
# Build source RPM for COPR submission
set -euo pipefail

VERSION=2.1.1
NAME=aic8800-dkms
TARDIR="${NAME}-${VERSION}"

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
WORKDIR=$(mktemp -d)
trap 'rm -rf "$WORKDIR"' EXIT

mkdir -p "$WORKDIR/$TARDIR"/{sdio-driver,usb-driver,pcie-driver,firmware}

# Copy SDIO driver source
cp -a "$SCRIPT_DIR/src/SDIO/driver_fw/driver/aic8800/"* "$WORKDIR/$TARDIR/sdio-driver/"

# Copy USB driver source
cp -a "$SCRIPT_DIR/src/USB/driver_fw/drivers/aic8800/"* "$WORKDIR/$TARDIR/usb-driver/"

# Copy PCIe driver source
cp -a "$SCRIPT_DIR/src/PCIE/driver_fw/driver/aic8800/"* "$WORKDIR/$TARDIR/pcie-driver/"

# Clean build artifacts from all trees
for tree in sdio-driver usb-driver pcie-driver; do
    find "$WORKDIR/$TARDIR/$tree" \
        -name '*.o' -o -name '*.ko' -o -name '*.mod' \
        -o -name '*.mod.c' -o -name '.*.cmd' -o -name '*.order' \
        -o -name '*.symvers' -o -name '.tmp_versions' \
        | xargs rm -rf 2>/dev/null || :
done

# Copy SDIO firmware
mkdir -p "$WORKDIR/$TARDIR/firmware/sdio"
cp -a "$SCRIPT_DIR/src/SDIO/driver_fw/fw/aic8800D80/"* "$WORKDIR/$TARDIR/firmware/sdio/"

# Copy USB firmware (multiple chip variants)
mkdir -p "$WORKDIR/$TARDIR/firmware/usb"
for fwdir in \
    "$SCRIPT_DIR/src/USB/driver_fw/fw/aic8800" \
    "$SCRIPT_DIR/src/USB/driver_fw/fw/aic8800D80" \
    "$SCRIPT_DIR/src/USB/driver_fw/fw/aic8800D80X2" \
    "$SCRIPT_DIR/src/USB/driver_fw/fw/aic8800DC"; do
    cp -a "$fwdir/"* "$WORKDIR/$TARDIR/firmware/usb/"
done

# Copy PCIe firmware (both D80 and D80X2 variants)
mkdir -p "$WORKDIR/$TARDIR/firmware/pcie"
for fwdir in \
    "$SCRIPT_DIR/src/PCIE/driver_fw/fw/aic8800D80" \
    "$SCRIPT_DIR/src/PCIE/driver_fw/fw/aic8800D80X2"; do
    cp -a "$fwdir/"* "$WORKDIR/$TARDIR/firmware/pcie/"
done

# Create tarball
mkdir -p "$HOME/rpmbuild/SOURCES"
tar -czf "$HOME/rpmbuild/SOURCES/${NAME}-${VERSION}.tar.gz" -C "$WORKDIR" "$TARDIR"

# Build SRPM
rpmbuild -bs "$SCRIPT_DIR/aic8800-dkms.spec"

echo ""
echo "SRPM built. Find it in $HOME/rpmbuild/SRPMS/"
echo "Submit to COPR with:"
echo "  copr-cli build <your-project> \$HOME/rpmbuild/SRPMS/${NAME}-${VERSION}-*.src.rpm"
