BLACK = { r = 0, g = 0, b = 0, a = 255 }
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
    x = 100,
    y = 10,
}

i = 1
t = {
    "ASDF",
    "SDFA",
    "DFAS",
    "FASD",
}

pdt = 1

function Update(dt)
    pdt = dt
    --print("dt: " .. dt)
    pos.x = pos.x + vel.x*dt
    pos.y = pos.y + vel.y*dt

    if pos.x > 800 then
        vel.x = - vel.x
    end
    if pos.y > 800 then
        vel.y = - vel.y
    end
    if pos.x < 0 then
        vel.x = - vel.x
    end
    if pos.y < 0 then
        vel.y = - vel.y
    end

    i = i + dt*10
    if i > 5 then i = 1 end
end

function Draw()
    gfx.clear(BACKGROUND)
    gfx.rect(10, 10, 100, 100, BLACK)
end

function Deinit()
    print("Bye")
end
