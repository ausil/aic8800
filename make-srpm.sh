#!/bin/bash
# Build source RPM for COPR submission
set -euo pipefail

VERSION=1.0.0
NAME=aic8800
TARDIR="${NAME}-${VERSION}"

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
WORKDIR=$(mktemp -d)
trap 'rm -rf "$WORKDIR"' EXIT

mkdir -p "$WORKDIR/$TARDIR"/{driver,firmware}

# Copy driver source
cp -a "$SCRIPT_DIR/src/SDIO/driver_fw/driver/aic8800/"* "$WORKDIR/$TARDIR/driver/"
# Clean build artifacts
find "$WORKDIR/$TARDIR/driver" -name '*.o' -o -name '*.ko' -o -name '*.mod' \
    -o -name '*.mod.c' -o -name '.*.cmd' -o -name '*.order' -o -name '*.symvers' \
    -o -name '.tmp_versions' | xargs rm -rf

# Copy firmware
cp -a "$SCRIPT_DIR/src/SDIO/driver_fw/fw/aic8800D80/"* "$WORKDIR/$TARDIR/firmware/"

# Create tarball
mkdir -p "$HOME/rpmbuild/SOURCES"
tar -czf "$HOME/rpmbuild/SOURCES/${NAME}-${VERSION}.tar.gz" -C "$WORKDIR" "$TARDIR"

# Build SRPM
rpmbuild -bs "$SCRIPT_DIR/aic8800-dkms.spec"

echo ""
echo "SRPM built. Find it in $HOME/rpmbuild/SRPMS/"
echo "Submit to COPR with:"
echo "  copr-cli build <your-project> \$HOME/rpmbuild/SRPMS/${NAME}-dkms-${VERSION}-*.src.rpm"
