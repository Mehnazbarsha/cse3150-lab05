# Lab 5 – Cosine Distance

## Purpose
Given a set of k-dimensional vectors, compute how similar they are by measuring 
the angle between them. Vectors pointing in the same direction have a small cosine 
distance (near 0), while opposite vectors have a large one (near pi).

## Build & Run

```bash
make          # build
make test     # run unit tests
make run_3d   # 3D sample
make run_5d   # 5D sample
```

**Input:** one vector per line, whitespace-separated, all same dimension k >= 2.

## Math
cos_distance(x, y) = acos( dot(x,y) / (|x|*|y|) )   in [0, pi]