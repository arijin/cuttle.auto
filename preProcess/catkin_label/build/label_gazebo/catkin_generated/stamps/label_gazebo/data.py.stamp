import yaml
import os
import sys
from pathlib import Path
import cv2

from utils.plots import Annotator, colors, save_one_box

FILE = Path(__file__).resolve()
ROOT = FILE.parents[0]  # YOLOv5 root directory
if str(ROOT) not in sys.path:
    sys.path.append(str(ROOT))  # add ROOT to PATH
ROOT = Path(os.path.relpath(ROOT, Path.cwd()))  # relative
print(ROOT)


class DetectMultiBackend():
    # YOLOv5 MultiBackend class for python inference on various backends
    def __init__(self, data=None):
        self.names = [f'class{i}' for i in range(1000)]  # assign defaults
        if data:  # data.yaml path (optional)
            with open(data, errors='ignore') as f:
                self.names = yaml.safe_load(f)['names']  # class names


if __name__ == '__main__':
    data = ROOT / '../data/coco128.yaml'
    print(data)
    model = DetectMultiBackend(data=data)
    names = model.names
    print(names)

    line_thickness = 2
    img_dir = str(ROOT / '../data/1.png')
    im0 = cv2.imread(img_dir)

    cls = 2
    conf = 0.7
    xyxy = [100, 200, 500, 820]
    c = int(cls)  # integer class
    label = f'{names[c]} {conf:.2f}'

    annotator = Annotator(im0, line_width=line_thickness, example=str(names))
    annotator.box_label(xyxy, label, color=colors(c, True))
    # Stream results
    im0 = annotator.result()

    cv2.imshow("aaa", im0)
    cv2.waitKey(5000)
    cv2.destroyAllWindows()
