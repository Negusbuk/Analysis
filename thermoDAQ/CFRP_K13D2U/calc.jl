function _dT(A, l, P, k)
    dT = P * l / (k * A);
    return dT;
end

function _P(A, l, dT, k)
    P = k * dT * A / l;
    return P;
end

function _k(A, l, dT, P)
    k = P * l / (A * dT);
    return k;
end

I = 0.099  # A
R = 10.0   # Ohm
P = I*I*R  # W

A = 9.80122e-3 * 275e-6; # m^2

slope_m = 0.1042990e3; # K/m
slope_0 = 0.0957354e3; # K/m
slope_p = 0.0871722e3; # K/m

An = 2.*14.2e-6; # m^2
kn = 0.26;       # W/m/K
Pn_m = _P(An, 1.0, slope_m, kn)
Pn_0 = _P(An, 1.0, slope_0, kn)
Pn_p = _P(An, 1.0, slope_p, kn)

println(Pn_m)
println(Pn_0)
println(Pn_p)

println(_k(A, 1.0, slope_m, P - Pn_m))
println(_k(A, 1.0, slope_0, P - Pn_0))
println(_k(A, 1.0, slope_p, P - Pn_p))
