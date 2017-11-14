open Express;

open ReactRouter;

type middlewareFn = (Request.t, Response.t, Next.t) => done_;

type method =
  | HEAD
  | GET
  | POST
  | PUT
  | DELETE;

type route =
  | Route((method, string, middlewareFn))
  | Use(middlewareFn)
  | UseWithPath((string, middlewareFn))
  | Static((string, string));

let applyRoute = (server, route) =>
  switch route {
  | Route((HEAD, _, _)) => Js_exn.raiseError("not implemented yet")
  | Route((GET, path, handler)) => App.get(server, ~path, Middleware.from(handler))
  | Route((POST, path, handler)) => App.post(server, ~path, Middleware.from(handler))
  | Route((PUT, _, _)) => Js_exn.raiseError("not implemented yet")
  | Route((DELETE, _, _)) => Js_exn.raiseError("not implemented yet")
  | Use(handler) => App.use(server, Middleware.from(handler))
  | UseWithPath((path, handler)) => App.useOnPath(server, ~path, Middleware.from(handler))
  | Static((path, folder)) =>
    App.useOnPath(
      server,
      ~path,
      Express.Static.make(folder, Express.Static.defaultOptions()) |> Express.Static.asMiddleware
    )
  };

let makeServer = (routes) => {
  let app = express();
  List.iter(applyRoute(app), routes);
  app
};

[@bs.val] external dirname : string = "__dirname";

[@bs.get_index] external gett : ('a, string) => Js.Json.t = "";

[@bs.send] external send : (Express.Response.t, string) => Express.done_ = "";

let geturl = (req) => gett(req, "url");

module type Cell = {
  type locals;
  let view: locals => string;
  let controller: (Express.Request.t, Express.Response.t, Express.Next.t) => Express.done_;
};

module IndexCell: Cell = {
  type locals = {app: string};
  let view = (locals: locals) => {
    let {app} = locals;
    {j|
      <html>
        <head>
          <link rel="stylesheet" href="/public/purecss.min.css" />
          <link href="/public/prism.css" rel="stylesheet" />
          <style>
            * {
                -webkit-box-sizing: border-box; /* Safari/Chrome, other WebKit */
                -moz-box-sizing: border-box; /* Firefox, other Gecko */
                box-sizing: border-box; /* Opera/IE 8+ */
            }
          </style>
        </head>
        <body style="margin: 0; padding: 0">
          <div class="app" style="line-height: 1.3; min-height: 100vh;">$(app)</div>
          <script src="/public/prism.js"></script>
          <script src="/public/bundle.js"></script>
        </body>
      </html>
    |j}
  };
  let controller = (req, res, _) => {
    let context = Js_json.object_ @@ Js_dict.empty();
    let location = geturl(req);
    let app =
      ReactDOMServerRe.renderToString @@ <ServerRouter context location> <Routes /> </ServerRouter>;
    send(res) @@ view({app: app})
  };
};

let routes = [
  Static(("/public", Node_path.resolve(dirname, "../../../public"))),
  Route((GET, "*", IndexCell.controller))
];

let app = makeServer(routes);

let safeGetEnv = (default, envvar) =>
  switch (Sys.getenv(envvar)) {
  | x => x
  | exception _ => default
  };

App.listen(app, ~port=int_of_string @@ safeGetEnv("3000", "SERVER_PORT"), ());
