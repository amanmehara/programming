$(document).ready(function () {
    $("#animate").click(function () {
        $("#toBeAnimated").animate({left: '256px'}, 4096);
    });
    $("#stopAnimation").click(function () {
        $("#toBeAnimated").stop();
    });
});