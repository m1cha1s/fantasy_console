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
}

function player:update(dt)
    self.vel.x = self.vel.x + self.acc.x*dt
    self.vel.y = self.vel.y + self.acc.y*dt

    self.pos.x = self.pos.x + self.vel.x*dt
    self.pos.y = self.pos.y + self.vel.y*dt

    self.acc.x = 0
    self.acc.y = 0
end

function Init()

end

function Update(dt)
    player:update(dt)
end

function Draw()
    gfx.clear({r=255,g=255,b=255})
    gfx.rect(player.pos.x+player.w/2, player.pos.y + player.h, player.w, player.h, {r=255})
end

function Deinit()

end
