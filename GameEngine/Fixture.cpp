#include "pch.h"
#include "Fixture.h"

Fixture::Fixture(b2Fixture* fixture) {
	_fixture = fixture;
}

std::unique_ptr<Body> Fixture::getBody() {
	Body body;
	body.setBody(_fixture->GetBody());

	return std::make_unique<Body>(body);
}

CustomUserData* Fixture::getUserData() {
	return (CustomUserData*)_fixture->GetUserData().pointer;
}

std::unique_ptr<FixtureFilter> Fixture::getFilterData() {
	const b2Filter& filterRaw = _fixture->GetFilterData();

	FixtureFilter filter;
	filter.categoryBits = filterRaw.categoryBits;
	filter.groupIndex = filterRaw.groupIndex;
	filter.maskBits = filterRaw.maskBits;

	return std::make_unique<FixtureFilter>(filter);
}

void Fixture::setFilterData(std::unique_ptr<FixtureFilter> filterData) {
	b2Filter filterRaw;
	filterRaw.categoryBits = filterData->categoryBits;
	filterRaw.groupIndex = filterData->groupIndex;
	filterRaw.maskBits = filterData->maskBits;

	_fixture->SetFilterData(filterRaw);
}