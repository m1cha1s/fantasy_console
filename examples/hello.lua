function Init()
    print("INIT")
end

function Update(dt)
    print("dt: " .. dt)
end

function Draw()
    gfx.clear(255,127,127,255)
end

function Deinit()
    print("Bye")
end
