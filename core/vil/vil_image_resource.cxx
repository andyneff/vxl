// This is mul/vil2/vil2_image_resource.cxx
#ifdef VCL_NEEDS_PRAGMA_INTERFACE
#pragma implementation
#endif
//:
// \file
// \author Ian Scott  ISBE Manchester
// \date   20 Sep 2002
//
//-----------------------------------------------------------------------------

#include "vil2_image_resource.h"
#include <vil2/vil2_image_view_base.h>

//--------------------------------------------------------------------------------

//: the reference count starts at 0.
vil2_image_resource::vil2_image_resource() : reference_count_(0) { }

vil2_image_resource::~vil2_image_resource() { }


bool vil2_image_resource::get_property(char const *, void *) const
{
  return false;
}


//: Check that a view will fit into the data at the given offset.
// This includes checking that the pixel type is scalar.
bool vil2_image_resource::view_fits(const vil2_image_view_base& im, unsigned i0, unsigned j0)
{
  return (i0 + im.ni() <= ni() && j0 + im.nj() <= nj() &&
    im.nplanes() == nplanes() &&
    vil2_pixel_format_num_components(im.pixel_format()) == 1);
}
