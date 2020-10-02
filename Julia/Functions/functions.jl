# Functions in Julia
# Navendu Pottekkat | 2020 | Apache-2.0 License
# https://www.apache.org/licenses/LICENSE-2.0

function vol_sphere(r)
    # Julia allows Unicode names (in UTF-8 encoding)
    # Either "pi" or the symbol π can be used
    return 4/3*pi*r^3
end
