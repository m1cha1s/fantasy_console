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



function player:update(dt)
    self.vel.x = self.vel.x + self.acc.x*dt
    self.vel.y = self.vel.y + self.acc.y*dt

    self.pos.x = self.pos.x + self.vel.x*dt
    self.pos.y = self.pos.y + self.vel.y*dt

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

    -- Draw ground
    gfx.rect(
        0, 600,
        800, 200,
        {}
    )
end

function Deinit()

end
