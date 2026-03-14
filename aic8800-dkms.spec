%global modversion 2.1.0

Name:           aic8800-dkms
Version:        %{modversion}
Release:        1%{?dist}
Summary:        AIC8800 WiFi/BT drivers (DKMS)
License:        GPL-2.0-only
URL:            https://github.com/radxa-pkg/aic8800

Source0:        %{name}-%{version}.tar.gz

BuildArch:      noarch

%description
DKMS kernel drivers for AIC8800 WiFi and Bluetooth chipsets,
supporting SDIO, USB, and PCIe attached devices.

# --- SDIO subpackage ---
%package -n aic8800-sdio-dkms
Summary:        AIC8800 SDIO WiFi/BT driver (DKMS)
BuildArch:      noarch
Requires:       dkms
Requires:       kernel-devel
Requires:       aic8800-firmware = %{version}-%{release}
Provides:       %{name} = %{version}-%{release}
Obsoletes:      %{name} < 2.0.0-1
Conflicts:      aic8800-usb-dkms
Conflicts:      aic8800-pcie-dkms

%description -n aic8800-sdio-dkms
DKMS kernel driver for AIC8800 SDIO WiFi and Bluetooth chipsets.
Automatically rebuilds on kernel updates. Provides modules:
aic8800_bsp (platform/firmware loader), aic8800_fdrv (WiFi),
aic8800_btlpm (Bluetooth low-power management).

# --- USB subpackage ---
%package -n aic8800-usb-dkms
Summary:        AIC8800 USB WiFi/BT driver (DKMS)
BuildArch:      noarch
Requires:       dkms
Requires:       kernel-devel
Requires:       aic8800-firmware = %{version}-%{release}
Conflicts:      aic8800-sdio-dkms
Conflicts:      aic8800-pcie-dkms

%description -n aic8800-usb-dkms
DKMS kernel driver for AIC8800 USB WiFi and Bluetooth chipsets
(AIC8800D80, AIC8800D80X2, AIC8800DC). Automatically rebuilds on
kernel updates. Provides modules: aic_load_fw (firmware loader),
aic8800_fdrv (WiFi).

# --- PCIe subpackage ---
%package -n aic8800-pcie-dkms
Summary:        AIC8800 PCIe WiFi driver (DKMS)
BuildArch:      noarch
Requires:       dkms
Requires:       kernel-devel
Requires:       aic8800-firmware = %{version}-%{release}
Conflicts:      aic8800-sdio-dkms
Conflicts:      aic8800-usb-dkms

%description -n aic8800-pcie-dkms
DKMS kernel driver for AIC8800D80 PCIe WiFi chipsets.
Automatically rebuilds on kernel updates. Provides module:
aic8800D80_fdrv (WiFi).

# --- Firmware subpackage ---
%package -n aic8800-firmware
Summary:        Firmware files for AIC8800 WiFi/BT chipsets
BuildArch:      noarch

%description -n aic8800-firmware
Firmware files for AIC8800 WiFi and Bluetooth chipsets, covering
SDIO, USB, and PCIe variants (AIC8800D80, AIC8800D80X2, AIC8800DC).

%prep
%autosetup

%install
# SDIO DKMS source
install -d %{buildroot}%{_usrsrc}/aic8800-sdio-%{modversion}
cp -a sdio-driver/* %{buildroot}%{_usrsrc}/aic8800-sdio-%{modversion}/

# USB DKMS source
install -d %{buildroot}%{_usrsrc}/aic8800-usb-%{modversion}
cp -a usb-driver/* %{buildroot}%{_usrsrc}/aic8800-usb-%{modversion}/

# PCIe DKMS source
install -d %{buildroot}%{_usrsrc}/aic8800-pcie-%{modversion}
cp -a pcie-driver/* %{buildroot}%{_usrsrc}/aic8800-pcie-%{modversion}/

# Firmware (transport-specific subdirs to avoid file conflicts)
install -d %{buildroot}/lib/firmware/aic8800/sdio
install -d %{buildroot}/lib/firmware/aic8800/usb
install -d %{buildroot}/lib/firmware/aic8800/pcie
install -p -m 644 firmware/sdio/* %{buildroot}/lib/firmware/aic8800/sdio/
install -p -m 644 firmware/usb/* %{buildroot}/lib/firmware/aic8800/usb/
install -p -m 644 firmware/pcie/* %{buildroot}/lib/firmware/aic8800/pcie/

# --- SDIO scriptlets ---
%post -n aic8800-sdio-dkms
dkms add -m aic8800-sdio -v %{modversion} --rpm_safe_upgrade
dkms build -m aic8800-sdio -v %{modversion}
dkms install -m aic8800-sdio -v %{modversion}

%preun -n aic8800-sdio-dkms
dkms remove -m aic8800-sdio -v %{modversion} --all --rpm_safe_upgrade || :

# --- USB scriptlets ---
%post -n aic8800-usb-dkms
dkms add -m aic8800-usb -v %{modversion} --rpm_safe_upgrade
dkms build -m aic8800-usb -v %{modversion}
dkms install -m aic8800-usb -v %{modversion}

%preun -n aic8800-usb-dkms
dkms remove -m aic8800-usb -v %{modversion} --all --rpm_safe_upgrade || :

# --- PCIe scriptlets ---
%post -n aic8800-pcie-dkms
dkms add -m aic8800-pcie -v %{modversion} --rpm_safe_upgrade
dkms build -m aic8800-pcie -v %{modversion}
dkms install -m aic8800-pcie -v %{modversion}

%preun -n aic8800-pcie-dkms
dkms remove -m aic8800-pcie -v %{modversion} --all --rpm_safe_upgrade || :

%files -n aic8800-sdio-dkms
%{_usrsrc}/aic8800-sdio-%{modversion}/

%files -n aic8800-usb-dkms
%{_usrsrc}/aic8800-usb-%{modversion}/

%files -n aic8800-pcie-dkms
%{_usrsrc}/aic8800-pcie-%{modversion}/

%files -n aic8800-firmware
%dir /lib/firmware/aic8800
/lib/firmware/aic8800/sdio/
/lib/firmware/aic8800/usb/
/lib/firmware/aic8800/pcie/

%changelog
* Fri Mar 13 2026 Dennis <dennis@ausil.us> - 2.1.0-1
- Add PCIe driver support (aic8800-pcie-dkms subpackage)
- Add PCIe firmware to aic8800-firmware
- Drop pre-6.1 kernel compat shims from PCIe driver

* Mon Mar 09 2026 Dennis <dennis@ausil.us> - 2.0.1-1
- Fix SDIO/USB firmware file collision (transport-specific subdirs)
- Firmware now in /lib/firmware/aic8800/sdio/ and /lib/firmware/aic8800/usb/

* Mon Mar 09 2026 Dennis <dennis@ausil.us> - 2.0.0-2
- Fix in_irq() removal in kernel 6.19 (use in_hardirq())

* Sun Mar 08 2026 Dennis <dennis@ausil.us> - 2.0.0-1
- Split into aic8800-sdio-dkms and aic8800-usb-dkms subpackages
- aic8800-sdio-dkms Provides/Obsoletes aic8800-dkms
- Port USB driver to kernel 6.18+
- Shared aic8800-firmware subpackage with all chip variants

* Sun Mar 08 2026 Dennis <dennis@ausil.us> - 1.0.0-1
- Initial DKMS package for kernel 6.18+
- Removed legacy kernel version ifdefs
- Converted firmware loading to request_firmware API
