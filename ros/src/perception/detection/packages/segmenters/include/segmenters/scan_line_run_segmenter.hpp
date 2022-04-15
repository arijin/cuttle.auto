/*
 * Copyright (C) 2019 by AutoSense Organization. All rights reserved.
 * Gary Chan <chenshj35@mail2.sysu.edu.cn>
 */
#ifndef SEGMENTERS_INCLUDE_SEGMENTERS_SCANLINERUN_SEGMENTER_HPP_
#define SEGMENTERS_INCLUDE_SEGMENTERS_SCANLINERUN_SEGMENTER_HPP_

#include <string>
#include <vector>

#include "segmenters/base_segmenter.hpp"

namespace autosense {
namespace segmenter {

class ScanLineRunSegmenter : public BaseSegmenter {
 public:
    ScanLineRunSegmenter();

    explicit ScanLineRunSegmenter(const SegmenterParams& params);

    ~ScanLineRunSegmenter();

    /// @brief Segment the point cloud.
    virtual void segment(
        const PointICloud& cloud_in,
        std::vector<PointICloudPtr>& cloud_clusters);  // NOLINT

    virtual std::string name() const { return "ScanLineRunSegmenter"; }

 private:
    SegmenterParams params_;

};  // class ScanLineRunSegmenter

}  // namespace segmenter
}  // namespace autosense

#endif  // SEGMENTERS_INCLUDE_SEGMENTERS_SCANLINERUN_SEGMENTER_HPP_
