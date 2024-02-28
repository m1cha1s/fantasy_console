BLACK = { r = 0, g = 0, b = 0, a = 255 }
BACKGROUND = { r=255,g=127,b=127,a=255 }

function Init()
    print("INIT")
end

function Update(dt)
    --print("dt: " .. dt)
end

function Draw()
    gfx.clear(BACKGROUND)
    gfx.text("Balls", 200, 200, 40, BLACK)
end

function Deinit()
    print("Bye")
end
