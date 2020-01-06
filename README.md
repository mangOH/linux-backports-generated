# Linux Backports for mangOH Yellow

The files present in this repository are generated as a result of a multi-step process. This
document attempts to describe the steps performed to reach re-create this content.

1. Create a directory to work in: `mkdir -p ~/mangOH_backports`
1. `cd ~/mangOH_backports`
1. Get a local copy of the mangOH backports repository:
   `git clone --branch swi_4.14.y https://github.com/mangOH/linux-backports.git`
1. Get a local copy of the stable Linux kernel tree:
   `git clone git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git`
1. Download the [zip file of the 2019-10-31 release of the Cypress FMAC driver](
   https://community.cypress.com/servlet/JiveServlet/download/17441-2-50210/cypress-fmac-v4.14.77-2019_1031.zip).
   The link to that zip was obtained from the [summary page](
   https://community.cypress.com/docs/DOC-17441).
1. Extract the zip file: `unzip cypress-fmac-v4.14.77-2019_1031.zip`
1. Extract the patches that came from the zip file:
   `tar -xf cypress-patch-v4.14.77-2019_1031.tar.gz`
1. Go into the kernel source directory: `cd ~/mangOH_backports/linux`
1. Create a new branch on which to apply the patches: `git checkout -b cypress_fmac_v4.14.77_20191031 v4.14.77`
1. Apply the patches: `git am ~/mangOH_backports/cypress-patch/*`
1. `cd ~/mangOH_backports/linux-backports`
1. Ensure that you have an up to date version of [coccinelle](
   https://github.com/coccinelle/coccinelle) installed. Version 1.0.8 is known to work.
1. Run this command to generatee the backports tree:
   `./gentree.py --clean --verbose --git-revision cypress_fmac_v4.14.77_20191031 ~/mangOH_backports/linux ~/mangOH_backports/generated`

At this point `~/mangOH_backports/generated` should contain a directory that is consistent with the
content of this git repository.  If you wish to manually perform a build, do the following.
1. `cd ~/mangOH_backports/generated`
1. Setup your toolchain using leaf
1. Set the backports config:
   `ARCH=arm CROSS_COMPILE=arm-poky-linux-gnueabi- KLIB=``findtoolchain wp77xx kernelroot`` KLIB_BUILD=``findtoolchain wp77xx kernelroot`` PATH=``findtoolchain wp77xx dir``:$PATH make defconfig-mangoh-yellow`
1. Build the backported modules:
   `ARCH=arm CROSS_COMPILE=arm-poky-linux-gnueabi- KLIB=``findtoolchain wp77xx kernelroot`` KLIB_BUILD=``findtoolchain wp77xx kernelroot`` PATH=``findtoolchain wp77xx dir``:$PATH make`
