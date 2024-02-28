BACKGROUND = { r=255,g=127,b=127,a=255 }

function Init()
    print("INIT")
end

function Update(dt)
    print("dt: " .. dt)
end

function Draw()
    gfx.clear(BACKGROUND)
end

function Deinit()
    print("Bye")
end
