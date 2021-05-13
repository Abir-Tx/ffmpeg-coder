# This is an example PKGBUILD file. Use this as a start to creating your own,
# and remove these comments. For more information, see 'man PKGBUILD'.
# NOTE: Please fill out the license field for your package! If it is unknown,
# then please put 'unknown'.

# Maintainer: Abir-Tx <abirtx@yandex.com>
pkgname=ffmpeg-coder
pkgver=2.0.0
pkgrel=1
epoch=
pkgdesc="A small cross platform CLI tool which will help in producing different types video converting codes quickly for new ffmpeg CLI users"
arch=(x86_64 i686)
url="https://github.com/Abir-Tx/ffmpeg-coder.git"
license=('MIT')
groups=()
depends=()
makedepends=(git make gcc)
checkdepends=()
optdepends=()
provides=(ffmpeg-coder)
conflicts=(ffmpeg-coder)
replaces=()
backup=()
options=()
install=
changelog=
source=("git+$url")
noextract=()
md5sums=(f8b683e201b3e9b1f003fef349f4a971)
validpgpkeys=()

prepare() {
	cd "$pkgname"
	make -f Makefile.own dir
}

build() {
	cd "$pkgname"
	make -f Makefile.own build
}

package() {
	cd "$pkgname"
	cp bin/ffmpeg-coder.o /bin
}
