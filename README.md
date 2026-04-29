# aic8800

[![Release](https://github.com/radxa-pkg/aic8800/actions/workflows/release.yaml/badge.svg)](https://github.com/radxa-pkg/aic8800/actions/workflows/release.yaml)

## Build

1. `git clone --recurse-submodules https://github.com/ausil/aic8800.git`
2. `./make-srpm.sh`
3. Build and install the SRPM

This repo is a fork of Radxa's The code has been updated to work on 6.18 and
newer kernels. There is also a COPR repo build from this tree that enables
the module to be built on Fedora systems using dkms.

To use the COPR Build run:

1. `sudo dnf copr enable ausil/aic8800-dkms`
2. `sudo dnf install aic8800-sdio-dkms` or `sudo dnf install aic8800-usb-dkms`

Depending on if you have a SDIO or USB connected device.

The Radxa Zero 3W has SDIO while the Dragon Q6A is USB attached
