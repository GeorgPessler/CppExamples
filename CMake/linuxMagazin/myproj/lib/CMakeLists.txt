set(libSrcs core.c util.c)

if(UNIX)
	set(libSrcs ${libSrcs} unixtool.c)
else(UNIX)
	set(libSrcs ${libSrcs} wintool.c)
endif(UNIX)

add_library(util SHARED ${libSrcs})

install(TARGETS util DESTINATION lib)


