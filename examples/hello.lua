BLACK = { r = 0, g = 0, b = 0, a = 255 }
BACKGROUND = { r=255,g=127,b=127,a=255 }

function Init()
    print("INIT")
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

    for x=0,800 do
        for y=0,800 do
            u = x/800
            v = y/800

            gfx.pixel(x, y, {r=255*u,g=255*v,b=127,a=255})
        end
    end

    --[[

    gfx.clear(BACKGROUND)

    gfx.text(tostring(1/pdt), 0, 0, 40, BLACK)

    gfx.text(t[math.floor(i)], pos.x, pos.y, 40, BLACK)
    --]]
end

function Deinit()
    print("Bye")
end
