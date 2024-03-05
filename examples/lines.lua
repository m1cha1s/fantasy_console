function Init() 
    math.randomseed(os.time())
end

function Update(dt) end

function Draw()
    -- gfx.clear({r=0,g=0,b=0})
    gfx.line(
        math.random(0,800),
        math.random(0,800),
        math.random(0,800),
        math.random(0,800),
        {
            r=math.random(0,255),
            g=math.random(0,255),
            b=math.random(0,255),
        }
    )
end

function Deinit() end
