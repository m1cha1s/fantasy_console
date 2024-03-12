local G = 6.6743e-11

local function sq(x) return x*x end

local function planet_new(x, y, r, m, color)
    return {
        pos = {
            x = x,
            y = y,
        },
        vel = {
            x = 0,
            y = 0,
        },
        acc = {
            x = 0,
            y = 0,
        },

        r = r,
        m = m,
        color = color,
    }
end

local function planet_apply_force(self, f)
    self.acc.x = f.x/self.m
    self.acc.y = f.y/self.m
end

local function planet_update(self, dt)
    self.vel.x = self.vel.x + self.acc.x*dt
    self.vel.y = self.vel.y + self.acc.y*dt

    self.pos.x = self.pos.x + self.vel.x*dt
    self.pos.y = self.pos.y + self.vel.y*dt

    self.acc.x = 0
    self.acc.y = 0
end

local function planet_attract(self, other)
    -- print(self)
    -- print(other)
    -- if self == other then return end

    local dx = other.pos.x-self.pos.x
    local dy = other.pos.y-self.pos.y

    local r2 = sq(dx)+sq(dy)
    local theta = m.atan2(dy, dx)
    
    local F = -G*self.m*other.m/r2

    local Fv = {
        x = m.cos(theta)*F,
        y = m.sin(theta)*F,
    }

    planet_apply_force(other, Fv)
end

local planet_colors = {
    {r=128,g=0,b=0},
    {r=0,g=128,b=0},
    {r=0,g=0,b=128},
    {r=128,g=128,b=0},
    {r=0,g=128,b=128},
    {r=128,g=0,b=128},
    {r=128,g=128,b=128},
}

local planets = {}

function Init()
    math.randomseed(os.time())

    for i=1,11,1 do
        local x = math.random(0, 800)
        local y = math.random(0, 800)
        local r = math.random(0, 80)
        local m = m.PI*sq(r)*1000000
        print(m)
        local color = planet_colors[math.random(1,#planet_colors)]
        planets[i] = planet_new(x,y,r,m,color)
    end
end

function Update(dt)
    for k1,p1 in pairs(planets) do
        for k2,p2 in pairs(planets) do
            if k1 ~= k2 then
                --print(k1, k2)
                planet_attract(p1, p2)
            end
        end
    end

    for k,p in pairs(planets) do
        print(k)
        planet_update(p, dt*1000)
    end
end

function Draw()
    gfx.clear({r=0,g=0,b=0})

    for k,planet in pairs(planets) do
        gfx.ellipse(
            planet.pos.x,
            planet.pos.y,
            planet.r,
            planet.r,
            planet.color
        )
    end
end

function Deinit() end
