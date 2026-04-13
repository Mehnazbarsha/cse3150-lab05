# Lab 5 – Cosine Distance

## Build & Run

```bash
make          # build
make test     # run unit tests
make run_3d   # 3D sample
make run_5d   # 5D sample
./build/cos_distance path/to/vectors.txt
```

**Input:** one vector per line, whitespace-separated, all same dimension k >= 2.

## Math
cos_distance(x, y) = acos( dot(x,y) / (|x|*|y|) )   in [0, pi]