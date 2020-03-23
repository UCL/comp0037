# The obstacle ID; unique for each obstacle
string name

# The probability that the obstacle exists
float32 probability_of_existence

# The mean wait time (in seconds) the obstacle will
# continue to exist. Time starts when the robot
# first encounters the obstacle
float32 mean_wait_time

# (Bottom left, top right) in world coordinates
stdr_msgs/FootprintMsg footprint
