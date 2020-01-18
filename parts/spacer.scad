/* Spacer for Aramcon Badge 2019 Upgrade Kit */

$fn=60;

height = 11.2;
step = 8;

translate([0, 0, step])
linear_extrude(height - step)
difference() {
    circle(r=2.5);
    circle(r=1.5);
}

linear_extrude(step)
difference() {
    circle(r=3.5);
    circle(r=1.5);
}
