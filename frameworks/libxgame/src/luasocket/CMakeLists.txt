set(LUASOCKET_HEADER
    src/luasocket/auxiliar.h
    src/luasocket/buffer.h
    src/luasocket/except.h
    src/luasocket/inet.h
    src/luasocket/io.h
    src/luasocket/luasocket_scripts.h
    src/luasocket/luasocket.h
    src/luasocket/mime.h
    src/luasocket/options.h
    src/luasocket/select.h
    src/luasocket/socket.h
    src/luasocket/tcp.h
    src/luasocket/timeout.h
    src/luasocket/udp.h
)
set(LUASOCKET_SRC
    src/luasocket/auxiliar.c
    src/luasocket/buffer.c
    src/luasocket/except.c
    src/luasocket/inet.c
    src/luasocket/io.c
    src/luasocket/luasocket_scripts.c
    src/luasocket/luasocket.c
    src/luasocket/mime.c
    src/luasocket/options.c
    src/luasocket/select.c
    src/luasocket/tcp.c
    src/luasocket/timeout.c
    src/luasocket/udp.c
    
)

if (WINDOWS)
    list(APPEND LUASOCKET_HEADER
        src/luasocket/wsocket.h
    )
    list(APPEND LUASOCKET_SRC
        src/luasocket/wsocket.c
    )
else()
    list(APPEND LUASOCKET_HEADER
        src/luasocket/unix.h
        src/luasocket/usocket.h
    )
    list(APPEND LUASOCKET_SRC
        src/luasocket/serial.c
        src/luasocket/unix.c
        src/luasocket/usocket.c
    )
endif()