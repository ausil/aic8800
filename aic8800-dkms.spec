%global modname aic8800
%global modversion 1.0.0
%global dkms_name %{modname}-%{modversion}

Name:           %{modname}-dkms
Version:        %{modversion}
Release:        1%{?dist}
Summary:        AIC8800 SDIO WiFi/BT driver (DKMS)
License:        GPL-2.0-only
URL:            https://github.com/radxa-pkg/aic8800

Source0:        %{modname}-%{version}.tar.gz

BuildArch:      noarch
Requires:       dkms
Requires:       kernel-devel
Requires:       %{modname}-firmware = %{version}-%{release}

%description
Kernel driver for AIC8800D80 SDIO WiFi and Bluetooth chipset.
Built via DKMS for automatic rebuild on kernel updates.

%package -n %{modname}-firmware
Summary:        Firmware files for AIC8800D80 WiFi/BT chipset
BuildArch:      noarch

%description -n %{modname}-firmware
Firmware files for the AIC8800D80 SDIO WiFi and Bluetooth chipset.

%prep
%autosetup -n %{modname}-%{version}

%install
# DKMS source
install -d %{buildroot}%{_usrsrc}/%{dkms_name}
cp -a driver/* %{buildroot}%{_usrsrc}/%{dkms_name}/

# Firmware
install -d %{buildroot}/lib/firmware/aic8800
install -p -m 644 firmware/* %{buildroot}/lib/firmware/aic8800/

%post
dkms add -m %{modname} -v %{modversion} --rpm_safe_upgrade
dkms build -m %{modname} -v %{modversion}
dkms install -m %{modname} -v %{modversion}

%preun
dkms remove -m %{modname} -v %{modversion} --all --rpm_safe_upgrade || :

%files
%{_usrsrc}/%{dkms_name}/

%files -n %{modname}-firmware
/lib/firmware/aic8800/

%changelog
* Sun Mar 08 2026 Dennis <dennis@ausil.us> - 1.0.0-1
- Initial DKMS package for kernel 6.18+
- Removed legacy kernel version ifdefs
- Converted firmware loading to request_firmware API
