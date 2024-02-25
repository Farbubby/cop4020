$(function () {
  $(".draggable").draggable();

  const pieces = $(".shuffle");
  pieces.each((i, piece) => {
    const randomX =
      Math.floor(Math.random() * 180) * (Math.random() < 0.5 ? -1 : 1);
    const randomY =
      Math.floor(Math.random() * 180) * (Math.random() < 0.5 ? -1 : 1);
    piece.style.transform = `translate(${randomX}px, ${randomY}px)`;
    piece.style.transition = "transform 1s ease";
  });

  setTimeout(() => {
    pieces.each((i, piece) => {
      piece.style.transform = "";
      piece.style.transition = "";
      piece.classList.add(`transition-${i + 1}`);
    });
  }, 1500);

  $("#up").on("click", () => {
    $("#target").animate({ top: "-=10px" }, 0);
  });

  $("#down").on("click", () => {
    $("#target").animate({ top: "+=10px" }, 0);
  });

  $("#left").on("click", () => {
    $("#target").animate({ left: "-=10px" }, 0);
  });

  $("#right").on("click", () => {
    $("#target").animate({ left: "+=10px" }, 0);
  });

  $(document).on("keydown", function (e) {
    if (e.key == "ArrowUp") {
      $("#target").animate({ top: "-=5px" }, 0);
    }
  });

  $(document).on("keydown", function (e) {
    if (e.key == "ArrowDown") {
      $("#target").animate({ top: "+=5px" }, 0);
    }
  });

  $(document).on("keydown", function (e) {
    if (e.key == "ArrowLeft") {
      $("#target").animate({ left: "-=10px" }, 0);
    }
  });

  $(document).on("keydown", function (e) {
    if (e.key == "ArrowRight") {
      $("#target").animate({ left: "+=10px" }, 0);
    }
  });
});
