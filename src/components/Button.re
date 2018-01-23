[%bs.raw {|require('./Button.css')|}];

let valueFromEvent = evt : string => (
                                       evt
                                       |> ReactEventRe.Form.target
                                       |> ReactDOMRe.domElementToObj
                                     )##value;

let component = ReasonReact.statelessComponent("Button");

let make = (~onClick, children) => {
  ...component,
  render: _self =>
    <MaterialUI.Button className="Button-root" onClick>
      children
    </MaterialUI.Button>
};