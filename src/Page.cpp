#include "Page.hpp"

Page::Page(size_t id)
{
	id_ = id;
}

Page::Page(const Page& page) {
	*this = page;
}

Page& Page::operator=(const Page& page) {
	id_ = page.getId();
	return *this;
}
