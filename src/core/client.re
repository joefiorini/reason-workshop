[@bs.val] external hot: bool = "module.hot";

[@bs.val]
external accept: (string, unit => unit) => unit = "module.hot.accept";

[@bs.module "react-hot-loader"]
external appContainer: ReasonReact.reactClass = "AppContainer";

module AppContainer = {
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=appContainer,
      ~props=Js.Obj.empty(),
      children,
    );
};

open ReactRouter;

let render = c =>
  ReactDOMRe.renderToElementWithClassName(
    <AppContainer> <BrowserRouter> (c()) </BrowserRouter> </AppContainer>,
    "app",
  );

render(_ => <Routes />);

[@bs.val] external highlightAll: unit => unit = "Prism.highlightAll";

if (hot) {
  /* accept "./routes.js" (fun _ => render (fun _ => <Routes />)); */
  accept("./routes.js", _ => {
    render(_ => <Routes />);
    highlightAll();
  });
};
