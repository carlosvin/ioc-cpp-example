FROM base/archlinux

RUN pacman -Sy gcc meson --noconfirm

WORKDIR /usr/src/ioc

ADD . .

RUN meson target .
WORKDIR /usr/src/ioc/target
RUN ninja test
