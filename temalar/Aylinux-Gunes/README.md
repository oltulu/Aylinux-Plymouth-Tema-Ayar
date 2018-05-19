# Plymouth Theme: Arch Sunrise

### A fork of "[Ubuntu Sunrise](http://gnome-look.org/content/show.php/Ubuntu+sunrise+plymouth?content=129696)" by Andre "Osku" Schmidt

## Arch Linux Dependencies
- [gdm-plymouth](https://aur.archlinux.org/packages/gdm-plymouth/)

>yaourt -S gdm-plymouth

- [v86d](https://aur.archlinux.org/packages/v86d/)

>yaourt -S v86d

- [sublime-text-dev](https://aur.archlinux.org/packages/sublime-text-dev/)

>yaourt -S sublime-text-dev

## Installation

_*This assumes you use Sublime Text and have linked it in your /usr/bin, eg:*_
>sudo ln -s /opt/sublime_text_3/sublime_text /usr/bin/sublime`

## Clone Plymouth Theme *Arch Sunrise* and add to Arch Linux

1. Create Workspaces directory
>mkdir -p ~/Workspace

2. Enter Directory
>cd ~/Workspace

3. Clone Repository
>git clone https://github.com/ElectricPrism/plymouth-theme-arch-sunrise.git

4. Copy Files into System
>sudo cp -R ~/Workspace/plymouth-theme-arch-sunrise /usr/share/plymouth/themes/arch-sunrise

5. Copy Framebuffer Fix
>sudo cp ~/Workspace/plymouth-theme-arch-sunrise/splash /etc/initramfs-tools/conf.d/

6. List Plymouth Themes
>plymouth-set-default-theme -l

7. Set Plymouth Theme
>plymouth-set-default-theme arch-sunrise

8. Rebuild Kernel (Is this necessary ???)
>mkinitcpio -p linux

## GRUB Based Boot Only

9. Update Grub Configuration to enable splash boot
>sudo sublime /etc/default/grub

>GRUB_CMDLINE_LINUX_DEFAULT="quiet splash"

10. Rebuild Grub (If you use Grub)
sudo grub-mkconfig -o /boot/grub/grub.cfg

11. Testing:
Switch to TTY-3 (Ctrl+Shift+F3)
Login as Root

```
plymouthd
plymouth --show-splash
```

_(Does this Work?)_

/usr/share/plymouth/themes/

sudo update-alternatives --install /lib/plymouth/themes/default.plymouth default.plymouth /lib/plymouth/themes/arch-sunrise/arch-sunrise.plymouth 200

sudo update-alternatives --config default.plymouth

_(Example of grub options in /etc/default ???)_

GRUB_CMDLINE_LINUX_DEFAULT='quiet splash'
GRUB_GFXMODE=auto
GRUB_GFXPAYLOAD_LINUX=keep


>sudo sublime /etc/default/grub


>sudo sublime /etc/mkinitcpio.conf

_Comment Out_

>\#GRUB_GFXPAYLOAD_LINUX=keep

_Rebuild Grub_
>sudo grub-mkconfig -o /boot/grub/grub.cfg

_Add Hook_
>sudo sublime /etc/mkinitcpio.conf

>ADD HOOK v86d

_\# Rebuild Linux Kernel_
sudo mkinitcpio -p linux
