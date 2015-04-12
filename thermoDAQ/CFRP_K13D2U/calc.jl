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

I = 0.1   # A
R = 5.0   # Ohm
P = I*I*R # W

A = 10e-3 * 275e-6; # m^2
slope = 0.08627e3;  # K/m

k = _k(A, 1.0, slope, P);

println(k)
