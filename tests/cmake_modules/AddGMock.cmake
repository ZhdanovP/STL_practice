macro(add_gmock)
    set(MOCKDIR ../../googletest)


    if(IS_DIRECTORY ${MOCKDIR})
        add_subdirectory(${MOCKDIR} ${LESSONS_ROOT}/gmock EXCLUDE_FROM_ALL)
    else()
        message(FATAL_ERROR "No ${MOCKDIR} found, can't add googletest")
    endif()
endmacro()
