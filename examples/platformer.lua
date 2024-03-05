local player = {
    pos = {
        x = 400,
        y = 400,
    },
    vel = {
        x = 0,
        y = 0,
    },
    acc = {
        x = 0,
        y = 0,
    },
    w = 20,
    h = 40,

    onGround = false,
}

local platform1 = {
    x = 600,
    y = 400,
    w = 60,
    h = 5,
    collidable = true,
}

local platforms = {platform1}

function player:collides(p)
    local dx = self.w/2

    local p1 = {x=self.pos.x-dx,self.pos.y-self.h}
    local p2 = {x=self.pos.x-dx,self.pos.y}
    local p3 = {x=self.pos.x+dx,self.pos.y-self.h}
    local p4 = {x=self.pos.x+dx,self.pos.y}
    
    return (p.x < p1.x and p.x+p.w > p1.x and p.y < p1.y and p.y+p.h > p1.y or
            p.x < p2.x and p.x+p.w > p2.x and p.y < p2.y and p.y+p.h > p2.y or
            p.x < p3.x and p.x+p.w > p3.x and p.y < p3.y and p.y+p.h > p3.y or
            p.x < p4.x and p.x+p.w > p4.x and p.y < p4.y and p.y+p.h > p4.y)
end

function player:update(dt)
    self.vel.x = self.vel.x + self.acc.x*dt
    self.vel.y = self.vel.y + self.acc.y*dt

    -- local ppos = {
    --     x = self.pos.x,
    --     y = self.pos.y,
    -- }

    self.pos.x = self.pos.x + self.vel.x*dt
    self.pos.y = self.pos.y + self.vel.y*dt

    -- local colided = false
    -- for k,p in platforms do
    --     if self:collides(p) then
    --         print("Collided")
    --         colided = true
    --         break
    --     end
    -- end
    -- if colided then
    --     -- Revert position change if we collided in the new position
    --     self.pos = ppos
    -- end

    self.acc.x = 0
    self.acc.y = 0
end

local function applyGravity()
    player.acc.y = player.acc.y + 98
end

local function applyFriction(coeff)
    player.acc.x = player.acc.x - player.vel.x*coeff
    player.acc.y = player.acc.y - player.vel.y*coeff
end

function Init()

end

function Update(dt)
    applyGravity()
    player:update(dt)

    -- Simple ground collision
    if player.pos.y > 600 then
        player.pos.y = 600
        player.vel.y = 0

        player.onGround = true
        applyFriction(3)
    else
        player.onGround = false
    end

    -- Handle input
    if btn.left() and player.onGround then
        player.acc.x = player.acc.x - 300
    end
    if btn.right() and player.onGround then
        player.acc.x = player.acc.x + 300
    end
    if btn.up() and player.onGround then
        player.acc.y = player.acc.y - 10000
    end
end

function Draw()
    gfx.clear({r=255,g=255,b=255})
    gfx.rect(player.pos.x-player.w/2, player.pos.y - player.h, player.w, player.h, {r=255})


    -- Draw platforms
    -- for k,p in platforms do
    --     gfx.rect(p.x,p.y,p.w,p.h, {r=0,g=127,b=0})
    -- end

    -- Draw ground
    gfx.rect(
        0, 600,
        800, 200,
        {}
    )
end

function Deinit()

end
