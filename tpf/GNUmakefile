all:
	cmake --build _build ${MAKE_FLAGS}
	_build/test

conf:
	rm -rfv _build
	mkdir -pv _build
	cd _build && cmake ../
	ln -sfv _build/compile_commands.json ./
