// This is brl/bseg/boxm2/pro/processes/boxm2_scene_bbox_process.cxx
//:
// \file
// \brief  A process for getting a BSTM scene's bounding box.
//
// \author Andrew Miller
// \date Dec 15, 2011

#include <bprb/bprb_func_process.h>
#include <vcl_iostream.h>
#include <vcl_string.h>
#include <vcl_vector.h>

#include <bstm/bstm_scene.h>
#include <vcl_compiler.h>

namespace {
const unsigned n_inputs_ = 1;
const unsigned n_outputs_ = 6;
}
bool bstm_scene_bbox_process_cons(bprb_func_process &pro) {
  vcl_vector<vcl_string> input_types_(n_inputs_);
  input_types_[0] = "bstm_scene_sptr";

  vcl_vector<vcl_string> output_types_(n_outputs_);
  output_types_[0] = "double"; // minx
  output_types_[1] = "double"; // miny
  output_types_[2] = "double"; // minz
  output_types_[3] = "double"; // maxx
  output_types_[4] = "double"; // maxy
  output_types_[5] = "double"; // maxz
  return pro.set_input_types(input_types_) &&
         pro.set_output_types(output_types_);
}

bool bstm_scene_bbox_process(bprb_func_process &pro) {
  if (pro.n_inputs() < ::n_inputs_) {
    vcl_cout << pro.name() << ": The input number should be " << ::n_inputs_
             << vcl_endl;
    return false;
  }

  // get the inputs
  bstm_scene_sptr scene = pro.get_input<bstm_scene_sptr>(0);

  // bbox and write out min/max pts
  vgl_box_3d<double> bbox = scene->bounding_box();

  // store outputs
  int i = 0;
  pro.set_output_val<double>(i++, bbox.min_x());
  pro.set_output_val<double>(i++, bbox.min_y());
  pro.set_output_val<double>(i++, bbox.min_z());
  pro.set_output_val<double>(i++, bbox.max_x());
  pro.set_output_val<double>(i++, bbox.max_y());
  pro.set_output_val<double>(i++, bbox.max_z());
  return true;
}
