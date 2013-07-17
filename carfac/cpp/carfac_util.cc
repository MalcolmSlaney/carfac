// Author: Alex Brandmeyer
//
// This file is part of an implementation of Lyon's cochlear model:
// "Cascade of Asymmetric Resonators with Fast-Acting Compression"
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "carfac_util.h"

ArrayX CARFACDetect(const ArrayX& x) {
  ArrayX conductance, z, set;
  FPType a = 0.175;
  // This offsets the low-end tail into negative x territory.
  // The parameter is adjusted for the book, to make the 20% DC response
  // threshold at 0.1.
  z  = x + a;
  // Zero is the final answer for many points.
  conductance = (z < 0).select(0.0, (z*z*z) / (z*z*z + z*z + 0.1));
  return conductance;
}