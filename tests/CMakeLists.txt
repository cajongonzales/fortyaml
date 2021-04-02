if (NOT GTEST_FOUND)
    include(FetchContent)
    FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG        release-1.10.0
	)
    set(FETCHCONTENT_QUIET OFF)
    SET(BUILD_GTEST ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()
include(GoogleTest)

