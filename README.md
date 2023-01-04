# **FDF_wireframe**
Discover the basics of graphics programming, in particular placing points in space, joining them and seeing the scene from a specific viewpoint

The representation in 3D of a landscape is a critical aspect of modern mapping. For example, in these times of spatial exploration, to have a 3D representation of Mars is a prerequisite condition to its conquest. As another example, comparing various 3D representations of an area of high tectonic
activity will allow you to better understand these phenomena and their evolution, and as a result, be better prepared.

Input:
---
- map example: 

<img src="https://user-images.githubusercontent.com/73645395/210597906-8f8ef1c0-4db8-4220-8d33-550dec16d4b7.png" alt="drawing" width="400"/>

- output example: 

<img src="https://user-images.githubusercontent.com/73645395/210598729-775554fa-c921-4094-bbf8-3de784d5e34c.png" alt="drawing" width="400"/>


- Each number represents a point in space:
  - The horizontal position corresponds to its axis.
  - The vertical position corresponds to its ordinate.
  - The value corresponds to its altitude.

Run:
----
- make
- ./fdf map   *(where map is a .fdf file containing the coordinates of the points on the map)*

Usefull info:
----
- [MLX](https://github.com/codam-coding-college/MLX42)
- [MLX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [Extra documentation](https://github.com/qst0/ft_libgfx)
