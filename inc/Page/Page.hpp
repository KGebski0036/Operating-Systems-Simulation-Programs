#pragma once

#include <cstdlib>

class Page
{
  public:
	Page(size_t id);

	Page(const Page& page);
	Page& operator=(const Page& page);

	size_t getId() const { return id_; }

  private:
	size_t id_;
};
