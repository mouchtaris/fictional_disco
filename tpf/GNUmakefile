all:
	make -C _build ${MAKE_FLAGS}
	_build/main

conf:
	rm -rfv _build
	mkdir -pv _build
	cd _build && cmake -G 'Unix Makefiles' ../
	ln -sfv _build/compile_commands.json ./
