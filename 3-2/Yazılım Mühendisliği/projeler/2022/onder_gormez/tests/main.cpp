#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>

int main(int argc, char *argv[])
{
    int result = Catch::Session().run(argc, argv);

    return result;
}
