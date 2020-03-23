# The obstacle ID; unique for each obstacle
string name

# The probability that the obstacle exists
float32 probability_of_existence

# The mean wait time (in seconds) the obstacle will
# continue to exist. If start_when_first_observed
# is set to true, the counter starts when the
# first observation of the obstacle is made. If
# set to false, it starts from simulation time.
bool start_when_first_observed
float32 mean_wait_time

# (Bottom left, top right) in world coordinates
stdr_msgs/FootprintMsg footprint
