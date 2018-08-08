module Route = {
  [@bs.module "react-router-dom"]
  external route: ReasonReact.reactClass = "Route";
  let make =
      (
        ~exact: bool,
        ~path: string,
        ~component: 'a => ReasonReact.reactElement,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=route,
      ~props={"exact": exact, "path": path, "component": component},
      children,
    );
};

module NavLink = {
  [@bs.module "react-router-dom"]
  external navLink: ReasonReact.reactClass = "NavLink";
  let make = (~_to: string, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=navLink,
      ~props={"to": _to},
      children,
    );
};

module BrowserRouter = {
  [@bs.module "react-router-dom"]
  external browserRouter: ReasonReact.reactClass = "BrowserRouter";
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=browserRouter,
      ~props=Js.Obj.empty(),
      children,
    );
};

module ServerRouter = {
  [@bs.module "react-router"]
  external staticRouter: ReasonReact.reactClass = "StaticRouter";
  let make = (~context: Js.Json.t, ~location: Js.Json.t, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=staticRouter,
      ~props={"context": context, "location": location},
      children,
    );
};

[@bs.module "react-router"]
external withRouter:
  ('a => ReasonReact.reactElement, 'a) => ReasonReact.reactElement =
  "";
