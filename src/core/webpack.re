type compiler;

[@bs.module] external webpack: Js.Json.t => compiler = "webpack";

[@bs.module]
external devMiddleware: (compiler, Js.Json.t) => 'a = "webpack-dev-middleware";

module WebpackStats = {
  type t;
  [@bs.get] external getFromLocals: 'a => t = "webpackStats";
  [@bs.send] external toJson: t => Js.Json.t = "toJson";
  [@bs.get]
  external assetsByChunkName: Js.Json.t => Js.Json.t = "assetsByChunkName";
  let getAssetsByChunkName = locals =>
    getFromLocals(locals) |> toJson |> assetsByChunkName;
};
