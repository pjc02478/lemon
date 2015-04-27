#define CATCH_CONFIG_MAIN
#include "stdafx.h"
#include "catch.h"

#include "../lemon/time/units.h"

using namespace lemon;

TEST_CASE("time::unit", "[time::unit]") {
	REQUIRE( time::second(1.4).to_s() == 1.4f );
	REQUIRE( time::millisecond(2000).to_s() == 2.0f);
	REQUIRE( time::frame<60>(30).to_s() == 1.0f / 60.0f * 30 );
	REQUIRE( time::frame<60>::spf == 1.0f / 60.0f );
}