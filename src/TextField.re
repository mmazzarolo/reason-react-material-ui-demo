[%bs.raw {|require('./TextField.css')|}];

type props = {
  value: string,
  onChange: (string) => 
};
let valueFromEvent = evt : string => (
                                       evt
                                       |> ReactEventRe.Form.target
                                       |> ReactDOMRe.domElementToObj
                                     )##value;

let component = ReasonReact.reducerComponent("TextField");

let make = (~value, ~onChange, _children) => {
  ...component,
  render: _self =>
    MaterialUI.(
      <FormControl className="TextField">
        <InputLabel
          _FormControlClasses={"focused": "TextField-focused"}
          htmlFor="custom-color-input">
          (ReasonReact.stringToElement(value))
        </InputLabel>
        <Input className="TextField-inputwrapper" />
      </FormControl>
    )
};