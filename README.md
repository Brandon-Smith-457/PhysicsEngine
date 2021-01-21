# PhysicsEngine
A C++ physics engine intended to interface with my GameEngine however should remain agnostic enough to interface with any rendering engine, for instructions on compilation please see my GameEngine.
* The code present in this engine is written with the intent for Game Physics, as such there might be inaccuracies in favour of reduced running times.  However for most applications the inaccuracy will be minimal enough to not matter.
  
---

**At the moment the engine is basically just a glorified gravity simulator, however it's the stepping stones necessary to be able to create proper projectile motion.**  
***TODO:***
* Create abstract collider class to check collisions between simple geometry (Circles, AxisAlignedBoundingBoxes, OrientedBoundingBoxes, Lines [All convex polygons can be modeled as a sequence of connected lines forming a closed loop])
* Implement static collision response:
  * Check for collision
  * Rewind "time" in the sense of moving rigidbody backwards until it is no longer touching (binary search with some threshold cutoff for how close the two bodies should be in the end)
  * Calculate the impulse response via the formula: j = -(1 + elasticity) * mass * normal velocity (this is a formula derived using many approximations and assumptions with the intent to sacrifice accuracy for performance, as mentioned above)
  
Once the above TODOs have been completed the basics for rigidbody simulation will be functioning, at which point the more complex problems of "relatively static collisions (ie two bodies, one resting on top of the other, the bottom being stationary or not)", or "GPU accelerated collision detections" will be tackled (As well as continuous collision detection).