BUILD_DIR ?= /tmp/build

conf:
	rm -rfv ${BUILD_DIR}
	mkdir -pv ${BUILD_DIR}
	root="$$(pwd)" && cd ${BUILD_DIR} && cmake "$$root"
build:
	cmake --build ${BUILD_DIR}

doc:
	${MAKE} -C doc html

.PHONY: \
	conf \
	doc \

