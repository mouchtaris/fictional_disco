all:
	make -C _build
	_build/panos
conf:
	rm -rfv _build
	mkdir -pv _build
	cd _build && cmake -G 'Unix Makefiles' ../
	ln -sfv _build/compile_commands.json .
