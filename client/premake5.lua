


workspace("polyrik")
    configurations({"debug", "release"})
    toolset("gcc")

    project("glad")
        kind("StaticLib")
        language("C")
        files("lib/glad/src/*.c")
        includedirs("lib/glad/inc/glad")
        filter("configurations:debug")
            warnings("High")
        filter("configurations:release")
            optimize("Speed")

    project("glpp")
        kind("StaticLib")
        language("C++")
        files("lib/glpp/src/*.cpp")
        includedirs({"lib/glpp/inc/glpp", "lib/glad/inc"})
        filter("configurations:debug")
            warnings("High")
        filter("configurations:release")
            optimize("Speed")

    project("enet")
        kind("StaticLib")
        language("C")
        files("lib/enet/*.c")
        includedirs("lib/enet/include")
        filter("configurations:debug")
            defines("DEBUG")
            warnings("High")
        filter("configurations:release")
            optimize("Speed")

    project("enetpp")
        kind("StaticLib")
        language("C++")
        files("lib/enetpp/src/*.cpp")
        includedirs("lib/enetpp/inc/enetpp")
        filter("configurations:debug")
            warnings("High")
        filter("configurations:release")
            optimize("Speed")

    project("polyrik")
        kind("WindowedApp")
        language("C++")
        cppdialect("C++17")
        files("src/*.cpp")
        includedirs({"inc", "lib/glad/inc", "lib/glpp/inc", "lib/entt/src", "lib/enetpp/inc"})
        links({"dl", "glad", "glpp", "sfml-system", "sfml-window", "enetpp"})
        filter("configurations:debug")
            warnings("High")
        filter("configurations:release")
            optimize("Speed")


