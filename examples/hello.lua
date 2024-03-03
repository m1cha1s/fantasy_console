BLACK = { r = 0, g = 0, b = 0, a = 255 }
RED = { r = 255, g = 255, b = 0, a = 255 }
BACKGROUND = { r=255,g=127,b=127,a=255 }

function Init()
    print("INIT")

    -- initialize the random function
    math.randomseed(os.time())
end

local pos = {
    x = 0,
    y = 0,
}

local vel = {
    x = 0,
    y = 0,
}

local speed = 1000

function Update(dt)
    vel.x = 0
    vel.y = 0

    if btn.up() then vel.y = -speed end
    if btn.down() then vel.y = speed end
    if btn.left() then vel.x = -speed end
    if btn.right() then vel.x = speed end

    pos.x = pos.x + vel.x*dt
    pos.y = pos.y + vel.y*dt
end

function Draw()
    gfx.clear(BACKGROUND)
    gfx.rect(pos.x, pos.y, 100, 100, RED)
end

function Deinit()
    print("Bye")
end
